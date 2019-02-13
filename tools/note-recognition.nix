{ llvmPackages_7, pkgconfig, libpulseaudio, 
	alsaLib, cmake, qt5 }:

llvmPackages_7.stdenv.mkDerivation rec {

    name = "note-recognition-TEST";

    nativeBuildInputs = [ cmake qt5.full alsaLib ];
    src = ./..;
}
