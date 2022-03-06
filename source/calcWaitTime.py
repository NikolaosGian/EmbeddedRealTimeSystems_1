def main():
    for i in range (1,1000000,10000):
        fileOfProducer = open("/home/nickgian/Desktop/ESPX_2022/assignment_1/all_data/timeOnlyProducers/timeOnlyProducer_"+str(i)+".txt", "r")
        fileOfConsumer = open("/home/nickgian/Desktop/ESPX_2022/assignment_1/all_data/timeOnlyConsumers/timeOnlyConsumer_"+str(i)+".txt", "r")
        finalFile = open("/home/nickgian/Desktop/ESPX_2022/assignment_1/finalTimes/finalTime_"+str(i)+".txt","w")
        finalFile2 = open("/home/nickgian/Desktop/ESPX_2022/assignment_1/finalTimes/finalOnlyTime_"+str(i)+".txt","w")
        
        while True:
            file1 = fileOfProducer.readline()
            file2 = fileOfConsumer.readline()
            if file1 != '':
                value1 = float(file1)
                value2 = float(file2)
                finalFile.write("Thread Time " +str(i)+ " : "+str(abs((value2 - value1))) + "\n")
                finalFile2.write(str((value2 - value1)) +"\n")
            else:
                fileOfProducer.close()
                fileOfConsumer.close()
                finalFile.close()
                break

def averageCalc():
    finalΑverage= open("/home/nickgian/Desktop/ESPX_2022/assignment_1/finalTimes/average.txt","w") ## file to write
    for i in range (1,1000000,10000):
        finalFile = open("/home/nickgian/Desktop/ESPX_2022/assignment_1/finalTimes/finalOnlyTime_"+str(i)+".txt","r") ## file to read
        counter = 0
        sum = 0
        while True:
            readFile = finalFile.readline()
            if readFile != '':
                val = float(readFile)
                sum = abs(sum + val)
                counter = counter + 1
            else:
                finalΑverage.write("Average FinalTime_"+str(i)+"= " + (str(sum/counter)) +"\n")
                finalFile.close()
                break

    finalΑverage.close()
    

if __name__=="__main__":
    main()
    averageCalc()