let
	nixpkgs = import <nixpkgs> {};
in
	nixpkgs.callPackage ./note-recognition.nix {}
