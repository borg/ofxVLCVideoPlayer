Andreas Borg notes to get VLC working on OSX
http;//crea.tion.to
2014/05/09, NYC

Modified with updates VLC sources, but still pretty dirty.
Works on oF 0.8
Using VLC compiled version 1.1.10.1 

Mix of VLC source files and the libs/plugins from install directory used.

Don't call the project VLC as that causes a name conflict

1. Set Build settings Header Search path
addons/ofxVLCVideoPlayer/lib recursive
 
2. Copy lib and plugins to data folder

3. Copy script to Build Phase>Run script which will copy them to right folder inside the app
 cp -r "$TARGET_BUILD_DIR/data/lib" "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/MacOS/"
 cp -r "$TARGET_BUILD_DIR/data/plugins" "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/MacOS/"
 
 4. Add src to xcode group
 5. Add only libvlc.dynlib and libvlcore.dynlib to target
 

Changed
+Added VLCMovie::readMetaData()
+Changed to make ofxVLCVideoPlayer::isLoaded() return true on meta data read
+Replaced deprecated method with libvlc_video_get_size(mp,num,&px,&py);
-Removed libvc_audio_output_set(mp, "waveout");




Original Windows notes

An openframeworks addon of video player using libvlc.

Written by NAKANO, Jun'ichi/Buffer Renaiss(junitium@nakano.gr.jp)
How to use:

1. Get VLC source and binary. (I used VLC 2.0.5 for development, probably 2.0.x or 2.1.x is OK)
   http://www.videolan.org/vlc/#download

2. Set include paths as following:
  a. libvlc SDK include dir (\Program Files (x86)\VideoLAN\VLC\sdk\include)
  b. VLC source include dir (VLC_SOURCE_PATH\vlc\include)
  c. VLC source lib dir (VLC_SOURCE_PATH\vlc\lib)

3. Link libvlc.lib, libvlccore.lib.

4. Copy VLC plugins folder(\Program Files (x86)\VideoLAN\VLC\plugins) to bin dir.

5. If you are developing with Visual Studio, change project's linker optimization setting /OPT:REF to /OPT:NOREF(On default, it is set on Release build).

2013/4/23


