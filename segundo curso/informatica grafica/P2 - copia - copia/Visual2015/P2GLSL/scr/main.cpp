#include "BOX.h"
#include <IGL/IGlib.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <list>
//using namespace std;

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>


//Idenficadores de los objetos de la escena
int objId =-1;
int modelId = -1;
glm::mat4 modelMatOfObj(1.0f);

//Declaración de CB
void resizeFunc(int width, int height);
void idleFunc();
void keyboardFunc(unsigned char key, int x, int y);
void mouseFunc(int button, int state, int x, int y);
void mouseMotionFunc(int x, int y);
void loadModel();


int main(int argc, char** argv)
{
	std::locale::global(std::locale("spanish"));// acentos ;)
	if (!IGlib::init("../shaders_P2/shader.v2.3.vert", "../shaders_P2/shader.v2.3.frag"))
		return -1;
   
	//CBs
	IGlib::setResizeCB(resizeFunc);
	IGlib::setIdleCB(idleFunc);
	IGlib::setKeyboardCB(keyboardFunc);
	IGlib::setMouseCB(mouseFunc);
	
	//Load model
	loadModel();
	modelMatOfObj = glm::scale(glm::mat4(1.0f), glm::vec3(0.3, 0.3, 0.3));
	IGlib::setModelMat(modelId, modelMatOfObj);

	//Se ajusta la cámara
	//Si no se da valor se cojen valores por defecto
	glm::mat4 view = glm::mat4(1.0);
	view[3].z = -6;

	glm::mat4 proj = glm::mat4(1.0);
	float f = 1.0f / tan(3.141592f / 6.0f);
	float far = 10.0f;
	float near = 0.1f;

	proj[0].x = f;
	proj[1].y = f;
	proj[2].z = (far + near) / (near - far);
	proj[2].w = -1.0f;
	proj[3].z = (2.0f * far * near) / (near - far);
	proj[3].w = 0.0f;
	IGlib::setProjMat(proj);
	IGlib::setViewMat(view);

	//Creamos el objeto que vamos a visualizar
	objId = IGlib::createObj(cubeNTriangleIndex, cubeNVertex, cubeTriangleIndex, 
			cubeVertexPos, cubeVertexColor, cubeVertexNormal,cubeVertexTexCoord, cubeVertexTangent);
	IGlib::addColorTex(objId, "../img/color2.png");
	IGlib::addEmissiveTex(objId, "../img/emissive.png");
	IGlib::addSpecularTex(objId, "../img/specMap.png");
		
	glm::mat4 modelMat = glm::mat4(1.0f);
	IGlib::setModelMat(objId, modelMat);
	


	//CBs
	IGlib::setIdleCB(idleFunc);
	IGlib::setResizeCB(resizeFunc);
	IGlib::setKeyboardCB(keyboardFunc);
	IGlib::setMouseCB(mouseFunc);
  	IGlib::setMouseMoveCB(mouseMotionFunc);
	
	//Mainloop
	IGlib::mainLoop();
	IGlib::destroy();
	return 0;
}

void resizeFunc(int width, int height)
{
	//Ajusta el aspect ratio al tamaño de la venta
}

void idleFunc()
{
	glm::mat4 modelMat(1.0f);
	static float angle = 0.0f;
	angle = (angle > 3.141592f * 2.0f) ? 0 : angle + 0.0001f;
	modelMat = glm::rotate(modelMat, angle, glm::vec3(1.0f, 1.0f, 0.0f));

	IGlib::setModelMat(objId, modelMat);
}

void keyboardFunc(unsigned char key, int x, int y)
{
	std::cout << "Se ha pulsado la tecla " << key << std::endl << std::endl;
}

void mouseFunc(int button, int state, int x, int y)
{
	if (state==0)
		std::cout << "Se ha pulsado el botón ";
	else
		std::cout << "Se ha soltado el botón ";
	
	if (button == 0) std::cout << "de la izquierda del ratón " << std::endl;
	if (button == 1) std::cout << "central del ratón " << std::endl;
	if (button == 2) std::cout << "de la derecha del ratón " << std::endl;

	std::cout << "en la posición " << x << " " << y << std::endl << std::endl;
}

void mouseMotionFunc(int x, int y)
{

}

void loadModel() {
	//ASSIMP
	Assimp::Importer importer;

	const aiScene* scene = importer.ReadFile("../img/personaje.obj",
		aiProcess_CalcTangentSpace |
		aiProcess_Triangulate |
		aiProcess_JoinIdenticalVertices |
		aiProcess_SortByPType);

	const int modelNTriangleIndex = scene->mMeshes[0]->mNumFaces;
	const int modelNvertex = scene->mMeshes[0]->mNumVertices;

	unsigned int* modelTriangleIndex = new unsigned int[scene->mMeshes[0]->mNumFaces * 3];
	for (int i = 0; i < scene->mMeshes[0]->mNumFaces; i++) {
		aiFace triangulo = scene->mMeshes[0]->mFaces[i];
		modelTriangleIndex[i * 3] = triangulo.mIndices[0];
		modelTriangleIndex[i * 3 + 1] = triangulo.mIndices[1];
		modelTriangleIndex[i * 3 + 2] = triangulo.mIndices[2];
	}

	float* modelVertexPos = new float[scene->mMeshes[0]->mNumVertices * 3];
	for (int i = 0; i < scene->mMeshes[0]->mNumVertices; i++) {
		modelVertexPos[i * 3] = scene->mMeshes[0]->mVertices[i].x;
		modelVertexPos[i * 3 + 1] = scene->mMeshes[0]->mVertices[i].y;
		modelVertexPos[i * 3 + 2] = scene->mMeshes[0]->mVertices[i].z;
	}


	//Calculate normals
	float* modelVertexNormal = new float[scene->mMeshes[0]->mNumVertices * 3];

	int i1, i2, i3;
	glm::vec3 p1, p2, p3;
	const int faces = scene->mMeshes[0]->mNumFaces;
	std::list<glm::vec3>* listArray = new std::list<glm::vec3>[scene->mMeshes[0]->mNumFaces];


	for (int i = 0; i < scene->mMeshes[0]->mNumFaces; i++) {
		aiFace triangulo = scene->mMeshes[0]->mFaces[i];
		i1 = triangulo.mIndices[0];
		i2 = triangulo.mIndices[1];
		i3 = triangulo.mIndices[2];

		p1 = glm::vec3(modelVertexPos[i1 * 3], modelVertexPos[i1 * 3 + 1], modelVertexPos[i1 * 3 + 2]);
		p2 = glm::vec3(modelVertexPos[i2 * 3], modelVertexPos[i2 * 3 + 1], modelVertexPos[i2 * 3 + 2]);
		p3 = glm::vec3(modelVertexPos[i3 * 3], modelVertexPos[i3 * 3 + 1], modelVertexPos[i3 * 3 + 2]);

		listArray[i1].push_back(glm::cross(p2 - p1, p3 - p1));
		listArray[i2].push_back(glm::cross(p3 - p2, p1 - p2));
		listArray[i3].push_back(glm::cross(p1 - p3, p2 - p3));
	}

	std::list<glm::vec3>::iterator it;
	glm::vec3 aux;

	for (int i = 0; i < scene->mMeshes[0]->mNumVertices; i++) {
		it = listArray[i].begin();

		aux = glm::vec3();

		for (int j = 0; j < listArray[i].size(); j++) {
			aux += ((*it));
			it++;
		}

		aux = glm::normalize(aux);
		modelVertexNormal[i * 3] = aux.x;
		modelVertexNormal[i * 3 + 1] = aux.y;
		modelVertexNormal[i * 3 + 2] = aux.z;
	}

	modelId = IGlib::createObj(modelNTriangleIndex, modelNvertex, modelTriangleIndex, modelVertexPos, modelVertexNormal);
}