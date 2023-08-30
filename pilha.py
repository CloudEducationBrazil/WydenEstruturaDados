def main():
    '''
    Esse programa mostra como um pilha pode ser utilizada
    para empilhar uma sequencia e
    imprimir a sequencia em ordem reversa
    '''

    seq = [1, 2, 3, 4]

    pilha = []
    for elemento in seq:
        pilha.append(elemento)
    
    print(pilha)

    while len(pilha) > 0:
        print(pilha)
        topo = pilha.pop()
        print("topo: ", topo)

main()