{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {

  nativeBuildInputs = with pkgs; [
    tree-sitter
    nodejs # tree-sitter generate
    graphviz # tree-sitter test --debug-graph && xdg-open log.html
  ];

  buildInputs = with pkgs; [
  ];

}
