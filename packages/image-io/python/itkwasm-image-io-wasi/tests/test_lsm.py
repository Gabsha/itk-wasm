from itkwasm_image_io_wasi import lsm_read_image

from .common import test_input_path

test_input_file_path = test_input_path / "cthead1.lsm"

def verify_image(image):
    assert image.imageType.dimension == 2
    assert image.imageType.componentType == "uint8"
    assert image.imageType.pixelType == "RGB"
    assert image.imageType.components == 4
    assert image.origin[0] == 0.0
    assert image.origin[1] == 0.0
    assert image.spacing[0] == 1.0e-8
    assert image.spacing[1] == 1.0e-8
    assert image.direction[0, 0] == 1.0
    assert image.direction[0, 1] == 0.0
    assert image.direction[1, 0] == 0.0
    assert image.direction[1, 1] == 1.0
    assert image.size[0] == 256
    assert image.size[1] == 256
    assert image.data.shape[1] == 256
    assert image.data.shape[0] == 256

def test_lsm_read_image():
    could_read, image = lsm_read_image(test_input_file_path)
    assert could_read
    verify_image(image)