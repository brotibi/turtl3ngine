#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in vec3 Normal;
in vec3 FragPos;
//uniform vec3 lightPos;


uniform sampler2D texture_diffuse1;
uniform sampler2D texture_specular1;
//uniform float ambientStrength;
//uniform vec4 lightColor;
uniform vec3 viewPos;

vec3 norm = normalize(Normal);
  

float specularStrength = 0.5;

struct Light {
    vec3 position;
    vec4 color;
    float ambientStrength;
};

struct DirectionalLight {
    vec3 direction;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    vec4 color;
    float ambientStrength;
};

struct PointLight {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadratic;

    vec4 color;
    float ambientStrength;
};

struct SpotLight {
    vec3 position;
    vec3 direction;
    float cutOff;

     vec4 color;
    float ambientStrength;
};

vec4 calculateDiffuse(vec3 lightDir, vec4 color);
vec4 calculateAmbient(float ambientStrength, vec4 color);
vec4 calculateSpecular(vec3 lightDir, vec4 color);
vec4 calculatePhongLighting(Light light);

vec4 calculateSpotLight();
vec4 calculatePointLight();
vec4 calculateDirectionalLight();

// Phong Lighting for Directional Lights
vec4 calculatePhongLighting(DirectionalLight light);
// Phong Lighting for Point Lights
vec4 calculatePhongLighting(PointLight light);
// Phong Lighting for Spot Lights
vec4 calculatePhongLighting(SpotLight light);

#define NR_LIGHTS 20
uniform Light lights[NR_LIGHTS];

// Specific lights
uniform SpotLight spotLights[NR_LIGHTS];
uniform PointLight pointLights[NR_LIGHTS];
uniform DirectionalLight directionalLights[NR_LIGHTS];

void main() {    
    
    vec4 result = vec4(0.f);

    /*for(int i = 0; i < lights.length; ++i) {
        if(lights[i].ambientStrength != 0.f) {
            //break;
            result += calculatePhongLighting(lights[i]);
        }
        
    }*/
    result += calculateSpotLight() + calculateDirectionalLight() + calculatePointLight();

    FragColor = result;
}

vec4 calculateDiffuse(vec3 lightDir, vec4 color) {
    
    vec4 diffuse;
    vec3 norm = normalize(Normal);
    
    float diff = max(dot(norm, lightDir), 0.0);
    diffuse = diff * color * texture(texture_diffuse1, TexCoords);

    return diffuse;
}

vec4 calculateAmbient(float ambientStrength, vec4 color) {
    return ambientStrength*color*texture(texture_diffuse1, TexCoords);
}

vec4 calculateSpecular(vec3 lightDir, vec4 color) {
    vec4 specular;

    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  

    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);

    specular = specularStrength * spec * color * texture(texture_specular1, TexCoords);  

    return specular;
}

vec4 calculatePhongLighting(Light light) {
    vec3 lightDir = normalize(light.position - FragPos);
    return calculateAmbient(light.ambientStrength, light.color) + calculateDiffuse(lightDir, light.color) + calculateSpecular(lightDir, light.color);
}

// Phong Lighting for Directional Lights
vec4 calculatePhongLighting(DirectionalLight light) {
    return calculateAmbient(light.ambientStrength, light.color) + calculateDiffuse(light.direction, light.color) + calculateSpecular(light.direction, light.color);
}

// Phong Lighting for Point Lights
vec4 calculatePhongLighting(PointLight light) {
    vec4 result;
    vec3 lightDir = normalize(light.position - FragPos);
    float distance = length(light.position - FragPos);
    float attenuation = 1.0/(light.constant + light.linear*distance + light.quadratic*(distance*distance));
    result = calculateAmbient(light.ambientStrength, light.color) + calculateDiffuse(lightDir, light.color) + calculateSpecular(lightDir, light.color);
    return attenuation*result;
}

// Phong Lighting for Spot Lights
vec4 calculatePhongLighting(SpotLight light) {
    return calculateAmbient(light.ambientStrength, light.color) + calculateDiffuse(light.direction, light.color) + calculateSpecular(light.direction, light.color);
}

vec4 calculateDirectionalLight() {
       vec4 result = vec4(0.f);

    for(int i = 0; i < directionalLights.length; ++i) {
        if(directionalLights[i].ambientStrength != 0.f) {
            result += calculatePhongLighting(directionalLights[i]);
        }
        
    }
    return result;
}

vec4 calculatePointLight() {
       vec4 result = vec4(0.f);

    for(int i = 0; i < pointLights.length; ++i) {
        if(pointLights[i].ambientStrength != 0.f) {
            result += calculatePhongLighting(pointLights[i]);
        }
        
    }
    return result;
}

vec4 calculateSpotLight() {
       vec4 result = vec4(0.f);

    for(int i = 0; i < spotLights.length; ++i) {
        if(spotLights[i].ambientStrength != 0.f) {
            result += calculatePhongLighting(spotLights[i]);
        }
        
    }
    return result;
}