import lldb
import subprocess
import sys

def install(package):
    subprocess.check_call([sys.executable, "-m", "pip", "install", package])

# Install NetworkX


def __lldb_init_module(debugger, internal_dict):
    # This function gets called when the script is imported by LLDB.
    print("Python debug_script loaded")
    install("networkx")

    # Create an LLDB CommandInterpreter instance
    ci = debugger.GetCommandInterpreter()
    
    # Example: Run 'thread list' LLDB command inside the debugger
    res = lldb.SBCommandReturnObject()
    ci.HandleCommand("thread list", res)
    if res.Succeeded():
        print("Threads in current process:")
        print(res.GetOutput())
    else:
        print("Failed to run 'thread list'")
