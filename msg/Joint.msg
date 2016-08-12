# Represents a KDL::Joint instance.

string name                   # name of the joint

uint8 type                    # type of the joint, default: Joint::None. One of...
uint8 RotAxis   = 0
uint8 RotX      = 1
uint8 RotY      = 2
uint8 RotZ      = 3
uint8 TransAxis = 4
uint8 TransX    = 5
uint8 TransY    = 6
uint8 TransZ    = 7
uint8 None_     = 8           # None is a reserved name in Python

float64 scale                 # scale between joint input and actual geometric
                              #   movement, default: 1
float64 offset                # offset between joint input and actual
                              #   geometric input, default: 0
float64 inertia               # 1D inertia along the joint axis, default: 0
float64 damping               # 1D damping along the joint axis, default: 0
float64 stiffness             # 1D stiffness along the joint axis, default: 0

Vector origin                 # the origin of the joint
Vector axis                   # the axis of the joint
