from cs50 import get_int


while True:
    n= get_int("Height: ")

    if n<9 and n>0:
        for i in range(n-1):
            print(" " *(n-(i+2)), "#" *(i+1) , "", "#"*(i+1))
        print("#" * n,"","#"*n)
        break