import subprocess
import os
import re
import argparse

# We want to call ETL's unpack.py program with every single file that follows the correct format

# First, find every single correct file and put it into a list
parser = argparse.ArgumentParser(description='A program to assist with unpacking files from the ETL database')
parser.add_argument('-f', '--force', action='store_true', help='whether to replace existing unpacked files (default: not set)')

force = parser.parse_args().force

os.chdir('unpack_etlcdb')

to_unpack = [file for file in os.listdir('ETL9G') if re.fullmatch(r"ETL9G_\d\d$", file)]
to_unpack.sort()

#print(to_unpack)

# Execute the unpack.py program on all of them

for file in to_unpack:
    # Only unpack file if it isn't already unpacked
    # If the force option is set, unpack it anyways
    if not os.path.exists('ETL9G/' + file + "_unpack") or force:
        subprocess.run(f'python3 unpack.py ETL9G/{file}',shell=True)