## [Boost.Program_options](http://www.boost.org/doc/libs/1_64_0/doc/html/program_options.html)

```sh
$ ./build/program_options --help
  -h [ --help ]         Print command line options.
  --opt1 arg
  --opt2 arg (=1)

$ ./build/program_options --opt1=2
opt1: 2, opt2: 1

$ ./build/program_options --opt1=2 --opt2=2
opt1: 2, opt2: 2
```