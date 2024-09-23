import boto3
import os

s3 = boto3.client("s3")

def download_dir(local_path, model_name):
    # s3_prefix = os.path.join("ml-models", model_name)
    os.makedirs(local_path, exist_ok=True)

    paginator = s3.get_paginator("list_objects_v2")
    paget_iterator = paginator.paginate(Bucket="jihwan-mlops")

    for result in paget_iterator:
        if "Contents" in result:
            for key in result["Contents"]:
                print(key)
                s3_key = key["Key"]
                local_file = os.path.join("ml-models", s3_key)
                s3.download_file("jihwan-mlops", s3_key, local_file)
