/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#include <emscripten.h>
#include <emscripten/bind.h>

#include "itkHDF5ImageIO.h"

#include "itkImageIOBaseJSBinding.h"

typedef itk::ImageIOBaseJSBinding< itk::HDF5ImageIO > HDF5ImageIOJSBindingType;

EMSCRIPTEN_BINDINGS(itk_hdf5_image_io_js_binding) {
  emscripten::register_vector<double>("AxisDirectionType");
  emscripten::enum_<HDF5ImageIOJSBindingType::IOPixelType>("IOPixelType")
    .value("UNKNOWNPIXELTYPE", itk::CommonEnums::IOPixel::UNKNOWNPIXELTYPE)
    .value("SCALAR", itk::CommonEnums::IOPixel::SCALAR)
    .value("RGB", itk::CommonEnums::IOPixel::RGB)
    .value("RGBA", itk::CommonEnums::IOPixel::RGBA)
    .value("OFFSET", itk::CommonEnums::IOPixel::OFFSET)
    .value("VECTOR", itk::CommonEnums::IOPixel::VECTOR)
    .value("POINT", itk::CommonEnums::IOPixel::POINT)
    .value("COVARIANTVECTOR", itk::CommonEnums::IOPixel::COVARIANTVECTOR)
    .value("SYMMETRICSECONDRANKTENSOR", itk::CommonEnums::IOPixel::SYMMETRICSECONDRANKTENSOR)
    .value("DIFFUSIONTENSOR3D", itk::CommonEnums::IOPixel::DIFFUSIONTENSOR3D)
    .value("COMPLEX", itk::CommonEnums::IOPixel::COMPLEX)
    .value("FIXEDARRAY", itk::CommonEnums::IOPixel::FIXEDARRAY)
    .value("MATRIX", itk::CommonEnums::IOPixel::MATRIX)
    ;
  emscripten::enum_<HDF5ImageIOJSBindingType::IOComponentType>("IOComponentType")
    .value("UNKNOWNCOMPONENTTYPE", itk::CommonEnums::IOComponent::UNKNOWNCOMPONENTTYPE)
    .value("UCHAR", itk::CommonEnums::IOComponent::UCHAR)
    .value("CHAR", itk::CommonEnums::IOComponent::CHAR)
    .value("USHORT", itk::CommonEnums::IOComponent::USHORT)
    .value("SHORT", itk::CommonEnums::IOComponent::SHORT)
    .value("UINT", itk::CommonEnums::IOComponent::UINT)
    .value("INT", itk::CommonEnums::IOComponent::INT)
    .value("ULONG", itk::CommonEnums::IOComponent::ULONG)
    .value("LONG", itk::CommonEnums::IOComponent::LONG)
    .value("ULONGLONG", itk::CommonEnums::IOComponent::ULONGLONG)
    .value("LONGLONG", itk::CommonEnums::IOComponent::LONGLONG)
    .value("FLOAT", itk::CommonEnums::IOComponent::FLOAT)
    .value("DOUBLE", itk::CommonEnums::IOComponent::DOUBLE)
    ;
  emscripten::class_<HDF5ImageIOJSBindingType>("ITKImageIO")
  .constructor<>()
  .function("SetNumberOfDimensions", &HDF5ImageIOJSBindingType::SetNumberOfDimensions)
  .function("GetNumberOfDimensions", &HDF5ImageIOJSBindingType::GetNumberOfDimensions)
  .function("SetFileName", &HDF5ImageIOJSBindingType::SetFileName)
  .function("GetFileName", &HDF5ImageIOJSBindingType::GetFileName)
  .function("CanReadFile", &HDF5ImageIOJSBindingType::CanReadFile)
  .function("ReadImageInformation", &HDF5ImageIOJSBindingType::ReadImageInformation)
  .function("WriteImageInformation", &HDF5ImageIOJSBindingType::WriteImageInformation)
  .function("SetDimensions", &HDF5ImageIOJSBindingType::SetDimensions)
  .function("GetDimensions", &HDF5ImageIOJSBindingType::GetDimensions)
  .function("SetOrigin", &HDF5ImageIOJSBindingType::SetOrigin)
  .function("GetOrigin", &HDF5ImageIOJSBindingType::GetOrigin)
  .function("SetSpacing", &HDF5ImageIOJSBindingType::SetSpacing)
  .function("GetSpacing", &HDF5ImageIOJSBindingType::GetSpacing)
  .function("SetDirection", &HDF5ImageIOJSBindingType::SetDirection)
  .function("GetDirection", &HDF5ImageIOJSBindingType::GetDirection)
  .function("GetDefaultDirection", &HDF5ImageIOJSBindingType::GetDefaultDirection)
  .function("SetPixelType", &HDF5ImageIOJSBindingType::SetPixelType)
  .function("GetPixelType", &HDF5ImageIOJSBindingType::GetPixelType)
  .function("SetComponentType", &HDF5ImageIOJSBindingType::SetComponentType)
  .function("GetComponentType", &HDF5ImageIOJSBindingType::GetComponentType)
  .function("GetImageSizeInPixels", &HDF5ImageIOJSBindingType::GetImageSizeInPixels)
  .function("GetImageSizeInBytes", &HDF5ImageIOJSBindingType::GetImageSizeInBytes)
  .function("GetImageSizeInComponents", &HDF5ImageIOJSBindingType::GetImageSizeInComponents)
  .function("SetNumberOfComponents", &HDF5ImageIOJSBindingType::SetNumberOfComponents)
  .function("GetNumberOfComponents", &HDF5ImageIOJSBindingType::GetNumberOfComponents)
  .function("Read", &HDF5ImageIOJSBindingType::Read)
  ;
}
