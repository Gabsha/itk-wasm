import numpy as np

from .int_types import IntTypes
from .float_types import FloatTypes

def _to_numpy_array(component_type, buf):
    if component_type == IntTypes.UInt8:
        return np.frombuffer(buf, dtype=np.uint8)
    elif component_type == IntTypes.Int8:
        return np.frombuffer(buf, dtype=np.int8)
    elif component_type == IntTypes.UInt16:
        return np.frombuffer(buf, dtype=np.uint16)
    elif component_type == IntTypes.Int16:
        return np.frombuffer(buf, dtype=np.int16)
    elif component_type == IntTypes.UInt32:
        return np.frombuffer(buf, dtype=np.uint32)
    elif component_type == IntTypes.Int32:
        return np.frombuffer(buf, dtype=np.int32)
    elif component_type == IntTypes.UInt64:
        return np.frombuffer(buf, dtype=np.uint64)
    elif component_type == IntTypes.Int64:
        return np.frombuffer(buf, dtype=np.int64)
    elif component_type == FloatTypes.Float32:
        return np.frombuffer(buf, dtype=np.float32)
    elif component_type == FloatTypes.Float64:
        return np.frombuffer(buf, dtype=np.float64)
    else:
        raise ValueError('Unsupported component type')

def _dtype_to_component_type(dtype):
    if dtype == np.uint8:
        return IntTypes.UInt8
    elif dtype == np.int8:
        return IntTypes.Int8
    elif dtype == np.uint16:
        return IntTypes.UInt16
    elif dtype == np.int16:
        return IntTypes.Int16
    elif dtype == np.uint32:
        return IntTypes.UInt32
    elif dtype == np.int32:
        return IntTypes.Int32
    elif dtype == np.uint64:
        return IntTypes.UInt64
    elif dtype == np.int64:
        return IntTypes.Int64
    elif dtype == np.float32:
        return FloatTypes.Float32
    elif dtype == np.float64:
        return FloatTypes.Float64
    else:
        raise ValueError('Unsupported dtype')