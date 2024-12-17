Import("env")
env.Replace(
    MKFSTOOL=env.get("PROJECT_DIR") + "/bin/mklittlefs"
)  # PlatformIO now believes it has actually created a SPIFFS
