def inverter_string(s):
    if len(s) <= 1:
        return s
    else:
        return s[-1] + inverter_string(s[:-1])
    
s="LEONARDO ROSSI"
resultado=inverter_string(s)

print("Inverso:",resultado)