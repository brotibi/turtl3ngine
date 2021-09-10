#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in vec3 Normal;
in vec3 FragPos;
uniform vec3 lightPos;


uniform sampler2D texture_diffuse1;
uniform sampler2D texture_specular1;
uniform float ambientStrength;
uniform vec4 lightColor;
uniform vec3 viewPos;

vec3 norm = normalize(Normal);
vec3 lightDir = normalize(lightPos - FragPos);  

float specularStrength = 0.5;


vec4 calculateDiffuse();
vec4 calculateAmbient();
vec4 calculateSpecular();
vec4 calculatePhongLighting();

void main() {    
    
    

    FragColor = lightColor;
}

vec4 calculateDiffuse() {
    
    vec4 diffuse;
    vec3 norm = normalize(Normal);
    
    float diff = max(dot(norm, lightDir), 0.0);
    diffuse = 1.0f * lightColor * texture(texture_diffuse1, TexCoords);

    return diffuse;
}

vec4 calculateAmbient() {
    return ambientStrength*lightColor;
}

vec4 calculateSpecular() {
    vec4 specular;

    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  

    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);

    specular = specularStrength * spec * lightColor * texture(texture_specular1, TexCoords);  

    return specular;
}

vec4 calculatePhongLighting() {
    return calculateAmbient() + calculateDiffuse() + calculateSpecular();
}