// FBXparser.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
#include"stdafx.h"
#include <fbxsdk.h>





/**
* Main function - loads the hard-coded fbx file,
* and prints its contents in an xml format to stdout.
*/
int main(int argc, char** argv) {

	// Change the following filename to a suitable filename value.
	WCHAR* lFilename = "../Asset/zebu.fbx";

	// Initialize the SDK manager. This object handles memory management.
	FbxManager* lSdkManager = FbxManager::Create();
	// Create the IO settings object.
	FbxIOSettings *ios = FbxIOSettings::Create(lSdkManager, IOSROOT);
	lSdkManager->SetIOSettings(ios);

	// Create an importer using the SDK manager.
	FbxImporter* lImporter = FbxImporter::Create(lSdkManager, "");

	// Use the first argument as the filename for the importer.
	if (!lImporter->Initialize(lFilename, -1, lSdkManager->GetIOSettings())) 
	{
		printf("Call to FbxImporter::Initialize() failed.\n");
		printf("Error returned: %s\n\n", lImporter->GetStatus().GetErrorString());
		exit(-1);
	}
	// Create a new scene so that it can be populated by the imported file.
	FbxScene* lScene = FbxScene::Create(lSdkManager, "myScene");

	// Import the contents of the file into the scene.
	lImporter->Import(lScene);

	// The file is imported, so get rid of the importer.
	lImporter->Destroy();





	// Destroy the SDK manager and all the other objects it was handling.
	lSdkManager->Destroy();



	return 0;
}
