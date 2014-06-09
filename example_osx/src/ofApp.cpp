#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    counter = 0;
	ofSetCircleResolution(50);
	ofBackground(255,255,255);
	bSmooth = false;
	ofSetWindowTitle("ofxVLCVideoPlayer example");
    
	ofSetFrameRate(60); // if vertical sync is off, we can go a bit fast... this caps the framerate at 60fps.
    
    fullscreen = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    player.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0,0,0);
    ofSetColor(255,255,255);
    
    ofDrawBitmapString("VLC Player in oF\nDrag and drop video. \nf - fullscreen \nUse mouse sideways to scrub\nMouse vertically to change volume", 10,10);
    if(player.isLoaded()){
        if((ofGetWidth() != player.getWidth() || ofGetHeight() != player.getHeight()) && !fullscreen){
            ofSetWindowShape(player.getWidth(), player.getHeight());
        }
    }
       
       
 player.draw(0,0,ofGetWidth(),ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key =='f'){
        fullscreen = !fullscreen;
        ofSetFullscreen(fullscreen);
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if(player.isLoaded()){
        player.setPosition(x/(float)ofGetWidth());
        player.setVolume((ofGetHeight()-y)/(float)ofGetHeight() *200);
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if(player.isPlaying()){
        player.pause();
    }else{
        player.play();
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
    if(dragInfo.files.size()>0){
        cout<<dragInfo.files[0]<<endl;
        player.stop();
        player.loadMovie(dragInfo.files[0],false);
        player.play();
    }
    
}
