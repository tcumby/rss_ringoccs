from conan.tools.files import copy

from conans.errors import ConanException


def deploy(graph, output_folder: str, **kwargs):
    # Note the kwargs argument is mandatory to be robust against future changes.
    for name, dep in graph.root.conanfile.dependencies.items():
        if dep.folders is None or dep.folders.source_folder is None:
            raise ConanException(
                f"Sources missing for {name} dependency.\n"
                "This deployer needs the sources of every dependency present to work, either building from source, "
                "or by using the 'tools.build:download_source' conf."
            )
        copy(
            graph.root.conanfile,
            "*",
            dep.folders.source_folder,
            output_folder,
        )
