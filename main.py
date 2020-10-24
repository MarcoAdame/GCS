

import ctypes
import pathlib
import random
import time

def main():
    # Load the shared library into c types.
    libname = pathlib.Path().absolute() / "libgcs.so"
    c_lib = ctypes.CDLL(libname)
    s = b'ACGT'
    s_len = len(s)
    #Call the C function using CTypes
    c_lib.gcs(s, s_len)
    
if __name__ == "__main__":
    main()

    
