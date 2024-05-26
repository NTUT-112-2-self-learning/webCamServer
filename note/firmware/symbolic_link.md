# symlink (symbolic link)

symbolic link is a file whose purpose is to point to a file or directory, it show like this when doing `ls -al` in the terminal

```bash
lrwxrwxrwx  1 james james    3 May 24 23:24 lib32 -> lib
```

in this case, there is no actual directory named in `lib32`, performing a `cd` operation on it will shows the contents from `lib`.
