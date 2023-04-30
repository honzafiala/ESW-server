with (import <nixpkgs> {});
mkShell {
	buildInputs = [
		pkg-config
		ninja
        protobuf
	];
}
