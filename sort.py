import shutil
import os
import re

# src dir - here are the un sorted files
src = "./.upload/"

# dist dirs - files will be sorted into these dirs
# var name is the three character id of the subject
buf = "./business-fundamentals/"
pro = "./programozas/"
szr = "./szamrend/"
imp = "./imperativ_programozas/"

# loads filenames in src dir to memory
for path, subdirs, files in os.walk(src):
    # loops through file names
    for filename in files:
        # creates the path for the src file
        srcpath = path + filename

        # checks the three cararacter prefix
        if re.search("^buf", filename):
            # copies the file and removes the prefix
            shutil.copyfile(srcpath, buf + filename.replace("buf_", ""))
            # deletes the old file
            os.remove(srcpath)

        if re.search("^pro", filename):
            shutil.copyfile(srcpath, pro + filename.replace("pro_", ""))
            os.remove(srcpath)

        if re.search("^szr", filename):
            shutil.copyfile(srcpath, szr + filename.replace("szr_", ""))
            os.remove(srcpath)
        
        if re.search("^imp", filename):
            shutil.copyfile(srcpath, imp + filename.replace("imp_", ""))
            os.remove(srcpath)
