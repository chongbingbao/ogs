# Source files
get_source_files(SOURCES)
append_source_files(SOURCES Adsorption)
append_source_files(SOURCES SolidModels)
append_source_files(SOURCES FractureModels)

append_source_files(SOURCES Fluid)
append_source_files(SOURCES Fluid/Density)
append_source_files(SOURCES Fluid/Viscosity)

append_source_files(SOURCES PorousMedium/Porosity)
append_source_files(SOURCES PorousMedium/Storage)
append_source_files(SOURCES PorousMedium/Permeability)

add_library(MaterialLib ${SOURCES} )
target_link_libraries(MaterialLib
    BaseLib
)
