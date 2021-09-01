#include "Camera.h"

Camera::Camera(glm::vec3 cameraPosition, glm::vec3 targetPosition) : Camera( cameraPosition, targetPosition, glm::vec3(0.0f, 1.0f, 0.0f)){
	this->targetPosition = targetPosition;
}

Camera::Camera(glm::vec3 cameraPosition, glm::vec3 targetPosition, glm::vec3 upVector) : VisualEntity(cameraPosition) {
	this->targetPosition = targetPosition;
	this->upVector = upVector;
	this->view = glm::lookAt(cameraPosition, targetPosition, upVector);
}

glm::mat4 Camera::getCameraView() {
	return this->view;
}

void Camera::setTargetPosition(glm::vec3 targetPosition) {
	this->targetPosition = targetPosition;
	this->view = glm::lookAt(this->getPosition(), targetPosition, this->upVector);
}

void Camera::setView(glm::vec3 cameraPosition, glm::vec3 targetPosition, glm::vec3 upVector) {
	this->targetPosition = targetPosition;
	this->upVector = upVector;
	this->view = glm::lookAt(cameraPosition, targetPosition, upVector);
}

void Camera::updateView() {
	this->view = glm::lookAt(this->getPosition(), this->targetPosition, this->upVector);
}

void Camera::setCaptureMouse(bool, GLFWwindow* window) {
	// tell GLFW to capture our mouse
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Camera::updateCameraDefMovement(float DeltaTime, GLFWwindow* window, glm::vec3 cameraFront) {
	this->setTargetPosition(this->getPosition() + cameraFront);
	float cameraSpeed = 2.5f * DeltaTime;
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		this->translate(cameraSpeed * cameraFront);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		this->translate(-cameraSpeed * cameraFront);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		this->translate(glm::normalize(glm::cross(cameraFront, this->upVector)) * -cameraSpeed);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		this->translate(glm::normalize(glm::cross(cameraFront, this->upVector)) * cameraSpeed);
}
void Camera::render(ShaderProgram& shader) {
	shader.use();
	shader.setMat4("projection", projection);
	shader.setMat4("view", this->view);
}
