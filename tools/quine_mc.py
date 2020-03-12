from quine_mccluskey.qm import QuineMcCluskey

def format_set(s):
    """
    Format a set of strings.
    """
    max_el = 50
    if not s:
        return ""
    l = list(s)
    ret = "'" + "', '".join(l[:min(max_el, len(s))]) + "'"
    if len(s) > max_el:
        ret = ret + ", ..."
    return ret

Arithmetic_Min_Terms = [4,5,12,13,20,21,28,29,36,37,39,44,45,47,52,53,55,60,61,63,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,198,206,214,222,230,238,246,254,3,9,11,19,25,27,35,41,43,51,57,59,232]
Flow_Min_Terms = [24,32,40,48,56,192,194,195,196,199,200,201,202,204,205,207,208,210,212,215,216,217,218,220,223,231,233,239,247,255]
Load_Min_Terms = [2,6,10,14,18,22,26,30,34,38,42,46,50,54,58,62,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,119,120,121,122,123,124,125,126,127,224,226,234,240,242,250,1,8,17,33,49,193,197,209,213,225,229,241,245,248,249]
Logical_Min_Terms = [7,15,23,31,203]
Misc_Min_Terms = [0,16,118,243,251]

qm = QuineMcCluskey(use_xor = False)

Arithmetic_Min_Terms_res = qm.simplify(Arithmetic_Min_Terms,[])
print("%25s:         [%s]" % ("Arithmetic_Min_Terms_res",format_set(Arithmetic_Min_Terms_res)))

Flow_Min_Terms_res = qm.simplify(Flow_Min_Terms,[])
print("%25s:         [%s]" % ("Flow_Min_Terms_res",format_set(Flow_Min_Terms_res)))

Load_Min_Terms_res = qm.simplify(Load_Min_Terms,[])
print("%25s:         [%s]" % ("Load_Min_Terms_res",format_set(Load_Min_Terms_res)))

Logical_Min_Terms_res = qm.simplify(Logical_Min_Terms,[])
print("%25s:         [%s]" % ("Logical_Min_Terms_res",format_set(Logical_Min_Terms_res)))

Misc_Min_Terms_res = qm.simplify(Misc_Min_Terms,[])
print("%25s:         [%s]" % ("Misc_Min_Terms_res",format_set(Misc_Min_Terms_res)))
