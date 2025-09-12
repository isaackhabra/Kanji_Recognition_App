from PIL import Image
import os
import re
import pandas as pd
import numpy as np

# First, get all of the directories that contain the cropped images

os.makedirs('dataset', exist_ok=True)
os.chdir('unpack_etlcdb/ETL9G')

dir_to_store = [dir for dir in os.listdir() if re.search(r'cropped', dir)]
#dir_to_store = ['ETL9G_02_unpack_cropped']

#dir_to_store.sort()
#print(dir_to_store)


for dir in dir_to_store:
  
    rows = []

    # Subtract 900 to get rid of the 9 from ETL9G
    folder_index = int("".join([char for char in dir if char.isdigit()])) - 900 
    #print(folder_index)
    for file in os.listdir(dir):
        row = []
        img_index = int("".join([char for char in file if char.isdigit()]))
        
        # Now, we want to find the original metadata csv file for this folder and look up what character the image represents
        
        with open(f'{dir.replace('_cropped', '')}/meta.csv', 'r') as meta:
            for i, line in enumerate(meta):
                if i == img_index + 1:
                    row.append(f'{line.split(',')[1]}')
                    
        # Write the black and white pixel values of the image
                    
        # May try changing to grayscale later to see if it's better
        img = Image.open(f'{dir}/{file}').convert('1')
        row.extend(np.array(img, dtype=np.uint8).flatten().tolist())
        rows.append(row)
        
        

    df = pd.DataFrame(rows)
    print(df)


    df.to_parquet(f'../../dataset/data.parquet_{re.search(r'\d\d', dir).group(0)}', index=False, engine='pyarrow')
    
    
