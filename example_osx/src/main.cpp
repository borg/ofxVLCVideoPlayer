#include "ofMain.h"
#include "ofApp.h"

//don't call the project VLC as that causes a name conflict

/*
 
 //copy lib and plugins to data folder
 //copy script to Build Phase>Run script which will copy them to right folder inside the app
 cp -r "$TARGET_BUILD_DIR/data/lib" "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/MacOS/"
 cp -r "$TARGET_BUILD_DIR/data/plugins" "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/MacOS/"
 

 */

//========================================================================
int main( ){
	ofSetupOpenGL(500, 500,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
