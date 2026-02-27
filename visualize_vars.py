import sys
sys.path.append('/usr/lib/python3/dist-packages')

import lldb
import networkx as nx
import matplotlib.pyplot as plt

def __lldb_init_module(debugger, internal_dict):
    # Entry point for LLDB Python script
    debugger.HandleCommand("command script add -f visualize_vars.visualize_vars visualize_vars")
    debugger.HandleCommand('target stop-hook add -o visualize_vars')
    print("The command 'visualize_vars' is ready. Run it in the debug console.")

def visualize_vars(debugger, command, result, internal_dict):
    print("This is about to do something cool with variables and pointers...")
    
    target = debugger.GetSelectedTarget()
    process = target.GetProcess()
    thread = process.GetSelectedThread()
    frame = thread.GetSelectedFrame()

    G = nx.DiGraph()

    for var in frame.GetVariables(True, True, False, True):
        var_name = var.GetName()
        var_value = var.GetValue()
        G.add_node(var_name, label=f"{var_name} = {var_value}")

        if var.GetType().IsPointerType() and var.GetValueAsUnsigned() != 0:
            ptr_addr = var.GetValue()
            try:
                deref = var.Dereference()
                deref_name = deref.GetName() or f"addr_{ptr_addr}"
                G.add_node(deref_name, label=f"{deref_name} = {deref.GetValue()}")
                G.add_edge(var_name, deref_name)
            except Exception as e:
                print(f"Failed to dereference {var_name}: {e}")
        print(f"Variable: {var_name}, Value: {var_value}")

    pos = nx.spring_layout(G)
    nx.draw_networkx_nodes(G, pos, node_color='lightblue', node_size=2000)
    labels = {n: d['label'] for n, d in G.nodes(data=True)}
    nx.draw_networkx_labels(G, pos, labels=labels)
    nx.draw_networkx_edges(G, pos, arrowstyle='->', arrowsize=20)
    plt.title("Variables and Pointers Visualization")
    plt.axis('off')
    plt.show()
