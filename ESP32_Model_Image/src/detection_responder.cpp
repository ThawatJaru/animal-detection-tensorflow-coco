/* Copyright 2019 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "detection_responder.h"
#include <Arduino.h>

// This dummy implementation writes person and no person scores to the error
// console. Real applications will want to take some custom action instead, and
// should implement their own versions of this function.
// void RespondToDetection(tflite::ErrorReporter *error_reporter, uint8_t Animal, uint8_t Non_Animal)
void RespondToDetection(tflite::ErrorReporter *error_reporter, uint8_t Animal, uint8_t Non_Animal)
{
    if (Animal > 130)
    {
        error_reporter->Report("Animal Detected!");
    }
    //else if (Non_Animal > 200)
    //{
        //error_reporter->Report("Non_Animal Detected!");
    //}
    
    error_reporter->Report("Non_Animal :%d Animal is:%d", Non_Animal, Animal);
    if (Animal > Non_Animal) 
    {
        // respond function when person is detected. 
        digitalWrite(LED_BUILTIN, Animal > Non_Animal);
        delay(1);
        digitalWrite(LED_BUILTIN, false);
    }
}
