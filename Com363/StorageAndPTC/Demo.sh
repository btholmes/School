eval "javac Demo/*.java"
read -rsp $'\nFiles compiled.\nPress enter to continue...\n\n\n'
eval "java Demo.CreateStorageMain"
eval "java Demo.ScanDataAndPopulateRelation"
read -rsp $'\nScanned and populated data. \nPress enter to continue...\n\n\n'
eval "java Demo.PrintRelation1"
read -rsp $'\nPrinted relation 1. \nPress enter to continue...\n\n\n'
eval "java Demo.ProcessRelation1"
read -rsp $'\nProcessed Relation 1. \nPress enter to continue...\n\n\n'
eval "java Demo.PrintRelation2"
read -rsp $'\nPrinted Relation 2. \nPress enter to continue...\n\n\n'
eval "java Demo.PrintRelation3"
read -rsp $'\nPrinted Relation 3. \nPress enter to continue...\n\n\n'
