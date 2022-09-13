from sympy import *

def pr(variable):
    print("var " + str(variable))
    print("Simplified:" + str(simplify(variable)))
    print("CNF:" + str(to_cnf(variable)))
    print("DNF:" + str(to_dnf(variable)))

def main():
    p,q = symbols('p,q')

    alpha = Xor(p, q)
    pr(alpha)

    beta = And(p , not q)
    test =  And(not p, q)
    charlie = Or(beta,test)
    pr(charlie)

if __name__ == "__main__":
    main()