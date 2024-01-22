import numpy as np

def matrix_to_text(matrix):
    return "".join(chr(val % 26 + 65) for row in matrix for val in row)

def text_to_matrix(text, n):
    return [[ord(char) - 65 for char in text[i:i+n]] for i in range(0, len(text), n)]

def encrypt_hill(plaintext, key_matrix):
    n = len(key_matrix)
    plaintext = plaintext.upper().replace(" ", "")
    while len(plaintext) % n != 0:
        plaintext += 'X'
    
    matrix = text_to_matrix(plaintext, n)
    result_matrix = np.dot(matrix, key_matrix) % 26

    return matrix_to_text(result_matrix)

def main():
    key = input("Enter the key (e.g., 'GYBNQKURP'): ")
    plaintext = input("Enter the plaintext: ")
    
    key_matrix = np.array(text_to_matrix(key, int(len(key)**0.5)))
    encrypted_text = encrypt_hill(plaintext, key_matrix)
    
    print("Hill Cipher (Encryption):", encrypted_text)

if __name__ == "__main__":
    main()
