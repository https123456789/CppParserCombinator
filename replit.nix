{ pkgs }: {
	deps = [
		pkgs.gcc
		pkgs.ccls
		pkgs.gnumake
        pkgs.cmake
        pkgs.python311
	];
}