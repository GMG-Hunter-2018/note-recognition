{ llvmPackages_8, pkgconfig, libpulseaudio, 
	alsaLib, cmake, qt5, gnumake }:

llvmPackages_8.stdenv.mkDerivation rec {

    name = "note-recognition-TEST";

    nativeBuildInputs = [ cmake qt5.full alsaLib gnumake ];
    src = ./..;
}
