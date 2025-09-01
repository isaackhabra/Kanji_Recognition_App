''' 
We want to trim some space from the outside of the images, because there's some residue from neighboring characters there
To do this, I'll crop the image to be 100x100, cropping away the upper 13, bottom 14, left 14, and right 14
'''

from PIL import Image
import os
import re

os.chdir('unpack_etlcdb/ETL9G')
dir_to_process = [dir for dir in os.listdir() if re.fullmatch(r"ETL9G_\d\d_unpack$", dir)]
#dir_to_process = ['ETL9G_01_unpack']

#dir_to_process.sort()
#print(dir_to_process)

for dir in dir_to_process:
    imgs_to_crop = [img for img in os.listdir(dir) if re.search('png', img)] 
    new_dir_name = dir+'_cropped'
    
    # Create new directory if it doesn't exist
    if not os.path.exists(new_dir_name):
        os.mkdir(new_dir_name)
        
    for img in imgs_to_crop:
        image = Image.open(dir + '/' + img)
        cropped_image = image.crop((14, 13, 114, 113))
        cropped_image.save(f'{new_dir_name}/cropped_{img}')
    

'''
image = Image.open('06077.png')

cropped_image = image.crop((14, 13, 114, 113))

cropped_image.save('cropped.png')
'''