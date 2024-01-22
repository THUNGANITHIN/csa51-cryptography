# Prompt user for input
key = input("Enter the key for Playfair cipher: ").upper().replace("J", "I")
plaintext = input("Enter the plaintext to encrypt: ").upper().replace("J", "I")

# Create Playfair matrix
alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ"
key_set = set(key)
matrix = [char for char in key_set.union(set(alphabet)) if char != 'J']
playfair_matrix = [matrix[i:i + 5] for i in range(0, 25, 5)]

# Encrypt the plaintext
ciphertext = ""
i = 0
while i < len(plaintext):
    char1, char2 = plaintext[i], 'X' if i == len(plaintext) - 1 or plaintext[i] == plaintext[i + 1] else plaintext[i + 1]
    row1, col1 = divmod(matrix.index(char1), 5)
    row2, col2 = divmod(matrix.index(char2), 5)

    if row1 == row2:
        ciphertext += playfair_matrix[row1][(col1 + 1) % 5] + playfair_matrix[row2][(col2 + 1) % 5]
    elif col1 == col2:
        ciphertext += playfair_matrix[(row1 + 1) % 5][col1] + playfair_matrix[(row2 + 1) % 5][col2]
    else:
        ciphertext += playfair_matrix[row1][col2] + playfair_matrix[row2][col1]

    i += 2

# Display the encrypted ciphertext
print("Encrypted ciphertext:",ciphertext)
