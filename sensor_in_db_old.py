import serial
import time
import pymysql

#port = '/dev/ttyACM0'
port = '/dev/ttyUSB0'
brate = 115200 #boudrate

ser = serial.Serial(port, brate)

sp = []
sp2 = []
reset = False
#reset = True

conn=pymysql.connect(host="relaxleep.ckbl1fdsxpkw.ap-northeast-2.rds.amazonaws.com",user="user",passwd="00000000",db="relaxleep")

while True:
    if reset:
	with conn.cursor() as cur:
	        sql = ["truncate TemHum_Table", "truncate CO2_Table", "truncate Cry_Table", "truncate TemPul_Table"]
        	for i in sql:
            		cur.execute(i)
           	 	conn.commit()
        print("complete!")
        break

    rxdata = ser.readline().decode('utf-8')
    ser.flushInput()
    ser.flushOutput()
    if '!' in rxdata:
        sp = rxdata.split('!')
        _sp = sp[1].split(',')
        if _sp[0] != '0':
            print("Hum : " + _sp[0])
            print("Temp : " + _sp[1])
            print("ppm : " + _sp[2])
            print("volt : " + _sp[3])
            with conn.cursor() as cur:
            	sql1 = "insert into TemHum_Table values(%s,%s,%s)"
            	sql2 = "insert into CO2_Table values(%s,%s)"
            	sql3 = "insert into Cry_Table values(%s,%s)"
            	cur.execute(sql1,(time.strftime("%m/%d %H:%M:%S",time.localtime()),_sp[1],_sp[0]))
            	cur.execute(sql2,(time.strftime("%m/%d %H:%M:%S",time.localtime()),_sp[2]))
            	cur.execute(sql3,(time.strftime("%m/%d %H:%M:%S",time.localtime()),_sp[3]))
            	conn.commit()
        time.sleep(5)
	#time.sleep(300)
    elif '@' in rxdata:
        sp2 = rxdata.split('@')
        _sp2 = sp2[1].split(',')
        # if _sp2[0] != '0.00':
            # print("bpm : " + _sp2[0])
            # print("% : " + _sp2[1])
            # with conn.cursor() as cur:
            	# sql1 = "insert into TemPul_Table values(%s,%s,%s)"
            	# cur.execute(sql1,(time.strftime("%m/%d %H:%M:%S",time.localtime()),_sp2[0],_sp2[1]))
            	# conn.commit()
        if _sp2[0] != '0.00' and _sp2[1] != "0\n":
            print("bpm : " + _sp2[0])
            print("% : " + _sp2[1])
            with conn.cursor() as cur:
            	sql1 = "insert into TemPul_Table values(%s,%s,%s)"
                if _sp2[0] > 50.0:
                    cur.execute(sql1,(time.strftime("%m/%d %H:%M:%S",time.localtime()),_sp2[0],_sp2[1]))
                    conn.commit()        
        time.sleep(1)
