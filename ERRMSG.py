# ERRMSG()
# This function will display an error meassage to the console, and provide an auditory warning.
def ERRMSG(string):
    import winsound
    duration = 500  # millisecond
    freq = 440  # Hz
    winsound.Beep(freq, duration)
    print(string)
    return

