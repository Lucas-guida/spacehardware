# frcord(Hour,Minute,Second)
# This function will produce the fractional hour format
# Input range:
# Hour: 0 - 23 hours
# Minute: 0 - 60 minutes
# Second: 0 - 60 seconds
def frcofd(HR,MI,SE):
    return (HR + MI/60 + SE/3600)/24
    

