import os
import hashlib
from collections import Counter

# ANSI escape codes for coloring text
class Color:
    PURPLE = '\033[95m'
    CYAN = '\033[96m'
    DARKCYAN = '\033[36m'
    BLUE = '\033[94m'
    GREEN = '\033[92m'
    YELLOW = '\033[93m'
    RED = '\033[91m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'
    END = '\033[0m'

def generate_sha256(file_path):
    """Generate SHA256 hash for a file."""
    sha256_hash = hashlib.sha256()
    with open(file_path, "rb") as f:
        for byte_block in iter(lambda: f.read(4096), b""):
            sha256_hash.update(byte_block)
    return sha256_hash.hexdigest()

def generate_sha256_for_files_in_folder(folder_path):
    """Generate SHA256 hashes for all files in a folder."""
    file_hashes = {}
    for root, _, files in os.walk(folder_path):
        for file_name in files:
            file_path = os.path.join(root, file_name)
            file_hash = generate_sha256(file_path)
            if file_hash in file_hashes:
                file_hashes[file_hash].append(file_path)
            else:
                file_hashes[file_hash] = [file_path]
    return file_hashes

if __name__ == "__main__":
    # folder_path = input("Enter the path of the folder: ")
    folder_path = "/home/james/projects/pythonProjects/hash_check/test_data/1"
    if os.path.isdir(folder_path):
        file_hashes = generate_sha256_for_files_in_folder(folder_path)
        for file_hash, file_paths in file_hashes.items():
            if len(file_paths) > 1:
                color = Color.GREEN
            else:
                color = Color.END
            for file_path in file_paths:
                id = file_path.split('/')[-1]
                print(f"File: {color}{id}{Color.END} | SHA256 Hash: {file_hash}")
    else:
        print("Invalid folder path.")
