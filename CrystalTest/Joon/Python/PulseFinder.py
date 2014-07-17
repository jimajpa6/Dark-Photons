import matplotlib.pyplot as plt

class Plotter(object):
    #datastring: array of strings containing voltage data
    def __init__(self, datastring, trigger = 1, rise = 1, tail = 1, filedir = "//"):
        self.datastring = datastring
        self.trigger = trigger
        self.rise = rise
        self.tail = tail
        self.filedir = filedir
        self.dta = []
        self.listofdata = []
    
    #filters the data
    def filterdata(self):
        for i in range(len(self.datastring)):
            """
            if self.datastring[i] == "[":
                pass
            elif "[" in self.datastring[i] and "]" in self.datastring[i]:
                tempstring = self.datastring[i][:len(self.datastring[i]) - 2]
                self.dta.append(float(tempstring))
            elif "[" in self.datastring[i]:
                tempstring = self.datastring[i][1:]
                self.dta.append(float(tempstring))
            elif "]" in self.datastring[i]:
                tempstring = self.datastring[i][:len(self.datastring[i]) - 1]
                self.dta.append(float(tempstring))
            else:
                self.dta.append(float(self.datastring[i]))
            """
            temp = self.datastring[i].translate(None, '[],')
            if temp == "":
                pass
            else:
                self.dta.append(float(temp))

    #given a a trigger value, and expected rise/fall times, 
    #returns a list of pulses
    def splicedata(self):
        i = 0
        while i < len(self.dta):
            pulsedata = []
            if self.dta[i] >= self.trigger: #if a pulse is found
                if self.rise < i: #checks to see if there's enough data before the pulse to give a complete rise
                    j = self.rise
                    while j != 0:
                        pulsedata.append(self.dta[i-j])
                        j -= 1
                else: #if not, select the data points where data begins
                    j = 0
                    while j != i:
                        pulsedata.append(self.dta[j])
                        j += 1
                #selects the data points that comprise the actual plot
                k = i
                while k < len(self.dta) and self.dta[k] >= self.trigger:
                    pulsedata.append(self.dta[k])
                    k += 1
                #add the data points that comprise the tail, or until data ends
                l = 0
                while k < len(self.dta) and l < self.tail:
                    pulsedata.append(self.dta[k])
                    l += 1
                    k += 1
                self.listofdata.append(pulsedata)
                i = k
            else:
                i += 1
        #throws out pulses cut off by the thread switching
        l = 0
        while l < range(len(self.listofdata)):
            for m in range(self.rise,len(self.listofdata[l]) - self.tail):
                if self.listofdata[l][m] == -10:
                    self.listofdata.pop(l)
                    break
                    
    
    #Simple plot
    def plotsimple(self, start = -1, end = -1):
        if start == -1 and end == -1:
            plt.plot(self.dta)
            plt.savefig(self.filedir + "//simpleplot.png", dpi = 500)
            plt.close()
        else:
            plt.plot(self.dta[start:end])
            plt.savefig(self.filedir + "//simpleplot%s" % (start) + "to" + str(end) + ".png", dpi = 500)
            plt.close()
    
    #Plots all pulses together on one graph,
    #then saves it as plot.png
    def plotdatatog(self):
        for item in self.listofdata:
            plt.plot(item)
        plt.savefig(self.filedir + "//plot.png", dpi = 500)
        plt.close()

    #Plots all pulses separately on individual graphs,
    #then saves them as plotn.png, where n is the plot number
    def plotdatasep(self):
        for i in range(0,len(self.listofdata)):
            plt.plot(self.listofdata[i])
            savename = "//plot%s.png" % (i + 1)
            plt.savefig(self.filedir + savename, dpi = 500)
            plt.close()
            
    #Saves pulses to textfile
    def savepulses(self):
        txtfl = open(self.filedir + "//pulses.txt", 'w')
        txtfl.write(str(self.listofdata))
        txtfl.close()

def main():
    voltagedata = open("voltagedataTEMP.txt", 'r')
    voltages = voltagedata.read().split()
    pltr = Plotter(voltages, 20, 5, 5, filedir = "//Users//Joon//OneDrive//Cornell//LEPPSummer2014DarkPhoton//Plots")
    pltr.filterdata()
    pltr.splicedata()
    pltr.plotdatatog()
    pltr.plotdatasep()
    voltagedata.close()

if __name__ == '__main__':
    main()