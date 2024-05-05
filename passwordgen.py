import random
import string

def generate_password(length=12):
    characters = string.ascii_letters + string.digits + string.punctuation
    password = ''.join(random.choice(characters) for i in range(length))
    return password

# Generate a password with default length of 12 characters
print(generate_password())

# Generate a password with custom length, e.g., 16 characters
print(generate_password(16))