# Represents a KDL::Segment instance.
#
# This class encapsulates a simple segment, that is a "rigid body"
# (i.e., a frame and a rigid body inertia) with a joint and with "handles",
# root and tip to connect to other segments.
#

string name                   # name of the segment
Joint joint                   # joint of the segment, default: Joint(Joint::None)
Frame f_tip                   # frame from the end of the joint to the tip of
                              #   the segment, default: Frame::Identity()
RigidBodyInertia I            # rigid body inertia of the segment, default: Inertia::Zero()
