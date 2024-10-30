
import os

# Define the project structure as a dictionary
project_structure = {
    "gbr_d": {
        "CMakeLists.txt": None,
        "Dockerfile": None,
        "README.md": None,
        "src": {
            "main.cpp": None,
            "GBRDaemon.cpp": None,
            "GBRDaemon.h": None,
            "router": {
                "GBRRouter.cpp": None,
                "GBRRouter.h": None,
                "RoutingAlgorithm.h": None,
                "GravityRouting.cpp": None,
                "GravityRouting.h": None,
                "BackpressureRouting.cpp": None,
                "BackpressureRouting.h": None,
            },
            "neighbor": {
                "GBRNeighbor.cpp": None,
                "GBRNeighbor.h": None,
            },
            "packet": {
                "GBRPacket.cpp": None,
                "GBRPacket.h": None,
                "HelloPacket.cpp": None,
                "HelloPacket.h": None,
                "DbDescriptionPacket.cpp": None,
                "DbDescriptionPacket.h": None,
                "LsaPacket.cpp": None,
                "LsaPacket.h": None,
            },
            "lsa": {
                "LSA.cpp": None,
                "LSA.h": None,
            },
            "lsdb": {
                "LSDB.cpp": None,
                "LSDB.h": None,
            },
            "nsa": {
                "NSA.cpp": None,
                "NSA.h": None,
            },
            "nsdb": {
                "NSDB.cpp": None,
                "NSDB.h": None,
            },
            "table": {
                "RoutingTable.cpp": None,
                "RoutingTable.h": None,
            },
            "utils": {
                "ConfigParser.cpp": None,
                "ConfigParser.h": None,
                "Logger.cpp": None,
                "Logger.h": None,
                "NetworkUtils.cpp": None,
                "NetworkUtils.h": None,
            },
            "buffer": {
                "BufferManager.cpp": None,
                "BufferManager.h": None,
            },
            "priority": {
                "PriorityManager.cpp": None,
                "PriorityManager.h": None,
            },
            "path_selection": {
                "PathSelectionStrategy.h": None,
                "ShortestPathSelection.cpp": None,
                "ShortestPathSelection.h": None,
                "MultiPathSelection.cpp": None,
                "MultiPathSelection.h": None,
            },
        },
        "include": {
            "gbr_d_common.h": None,
        },
        "config": {
            "gbr_d.conf": None,
        },
        "tests": {
            "CMakeLists.txt": None,
            "test_GBRRouter.cpp": None,
            "test_LSDB.cpp": None,
            "test_NSDB.cpp": None,
            "test_RoutingTable.cpp": None,
            "test_GBRPacket.cpp": None,
        },
        "scripts": {
            "run_docker.sh": None,
            "build_docker.sh": None,
        },
    }
}

def create_structure(base_path, structure):
    for name, content in structure.items():
        path = os.path.join(base_path, name)
        if content is None:  # Create a file
            with open(path, 'w') as f:
                f.write("")  # Create an empty file
        else:  # Create a directory
            os.makedirs(path, exist_ok=True)
            create_structure(path, content)

# Set the base path for the project (current directory)
base_path = os.getcwd()
create_structure(base_path, project_structure)
