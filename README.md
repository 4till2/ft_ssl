# ft_ssl
A partial re-implementation of OpenSSL in C.

## Description
The goal of this project is to understand the behaviour of the OpenSSL library and gain an understanding of the fundamentals of cryptography by reimplementing some of its functionality from the ground up.

The implemented functionality closely mocks the behaviour found in `man openssl(1)`.

For a more thorough description and list of requirements (such as allowed functions) look at `ft_ssl_md5.en.pdf`.

### Functionality

The hashing functions have the following usage:
`[hash_type] [-pqr] [-s string] [files...]`

All hashing functions can read from `STDIN`, take any number of strings specified as args, or any number of files.

#### Supported Hash's:

`md5`

`sha256`

#### Supported flags:

`-p` - read from `STDIN`, echo the input and calculate the hash

`-q` - quiet mode

`-r` - reverse output format

`-s` - find the hash for the string to be given after this flag or in the following argument

### Usage

```
$ make
```

```
$ ./ft_ssl command [command opts] [command args]
```

### Dependencies
`gcc` is required for the build
