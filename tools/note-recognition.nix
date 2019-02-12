{ stdenv, pkgconfig, libpulseaudio, alsaLib, cmake, qt5 }:

stdenv.mkDerivation rec {
    name = "note-recognition-TEST";

    nativeBuildInputs = [ cmake qt5.full alsaLib ];

    #LD_LIBRARY_PATH = "${libpulseaudio}/lib";

    #PATH = "${stdenv.lib.makeBinPath [ pulseaudio ]}";

    src = ./..;
}
