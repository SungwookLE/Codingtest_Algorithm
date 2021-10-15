import numpy as np
import csv
import matplotlib.pyplot as plt
import os
import re
import sys

if __name__=="__main__" :


    if len(sys.argv) < 2:
        print("Usage: execute_file [test_case1] [test_case2] ...")
        sys.exit()

    test_cases=[]
    for i in range(len(sys.argv)):
        if i != 0:
            test_cases.append(sys.argv[i])
        
        
    path_dir=os.getcwd()
    file_list = os.listdir(path_dir)

    file_data = []
    for file_dat in file_list:
        if file_dat.find('.dat') is not -1:
            file_data.append(file_dat)
    print("TOTAL(ea): ", len(file_data))

    color_map_list = ['b','g','r','c','m','y','k']
    idx= 0;

    for name in file_data:
        for case_idx in range(len(test_cases)):
            if (name.find(test_cases[case_idx]) != -1):
                # READ FROM CSV
                file = open(name, mode="r", encoding='utf-8')
                #file_label = re.sub("SX00|HISTORY|.|dat|ROL|VS1173|Z0++000mg",'',name)
                file_label = re.sub('.ZO\S+|SX00','',name)

                print(file_label)
                reader = csv.reader(file,delimiter = "\t",)
                next(reader)
                data=[]
                for row in reader:
                    #20ANG, 21RATE
                    data.append([float(row[19]), float(row[20])])
                data = np.array(data)

                if (file_label.find('95%') is not -1):
                    plt.plot(data[:,0], data[:,1],'--',label=file_label, linewidth=0.5, color = color_map_list[idx//3%len(color_map_list)])
                elif (file_label.find('100%') is not -1):
                    plt.plot(data[:,0], data[:,1],'-',label=file_label, linewidth=1, color = color_map_list[idx//3%len(color_map_list)])
                elif (file_label.find('105%') is not -1):
                    plt.plot(data[:,0], data[:,1],'-.',label=file_label, linewidth=0.5, color = color_map_list[idx//3%len(color_map_list)])
                idx+=1;

    print("Print(ea): ", idx)

    plt.tight_layout()
    plt.xlabel('|Rangle|')
    plt.ylabel('|Rrate|')
    plt.grid()
    plt.legend()
    plt.title('Rangle VS. Rrate')
    plt.show()

