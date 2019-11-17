# Ratfor77

The code (public domain) was copied from the [Stanford Exploration Project](http://sepwww.stanford.edu/doku.php?id=sep:software:ratfor). The Makefile was updated, and a _hello world_ example added.

The purpose of this repository is to have a running `ratfor77` environment to get the examples from _Software Tools_ (Kernighan/Plauger) to run.

## Requirements

- `make`
- `gcc`
- `gcc-fortran`

## Howto

Build `ratfor77`:

    $ make ratfor77

Build and execute the _hello world_ example:

    $ make example/hello
    $ example/hello
