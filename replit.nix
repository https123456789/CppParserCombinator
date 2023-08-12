{ pkgs }: {
	deps = [
		pkgs.gcc13
		pkgs.ccls
		pkgs.gnumake
        pkgs.cmake
        pkgs.python311
	];
}