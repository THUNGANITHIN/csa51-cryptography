# Get user input
message = input("Enter the message to encrypt: ")
shift = int(input("Enter the shift value: "))

# Encryption
encrypted_message = ""
for char in message:
    if char.isupper():
        encrypted_message += chr((ord(char) + shift - 65) % 26 + 65)
    elif char.islower():
        encrypted_message += chr((ord(char) + shift - 97) % 26 + 97)
    else:
        encrypted_message += char

# Display the encrypted message
print("Encrypted message:", encrypted_message)
