# -*- coding: utf-8 -*-
"""
Created on Sun Jul 12 11:02:06 2020

@author: OHyic

"""
#Import libraries
import os
import concurrent.futures
import pickle
import glob
import pandas as pd
from GoogleImageScraper import GoogleImageScraper
from patch import webdriver_executable


def worker_thread(search_key):
    save_key, search_key = search_key
    image_scraper = GoogleImageScraper(
        webdriver_path, image_path, search_key, save_key, number_of_images, headless, min_resolution, max_resolution)
    image_urls = image_scraper.find_image_urls()
    image_scraper.save_images(image_urls, keep_filenames)

    #Release resources
    del image_scraper

if __name__ == "__main__":
    #Define file path
    webdriver_path = os.path.normpath(os.path.join(os.getcwd(), 'webdriver', webdriver_executable()))
    image_path = os.path.normpath(os.path.join(os.getcwd(), 'photos'))

    #Add new search key into array ["cat","t-shirt","apple","orange","pear","fish"]
    # search_keys = list(set(["cat", "t-shirt"]))
    with open("../pokemon_query.pkl", "rb") as pf:
        search_keys = pickle.load(pf)
    processed = {os.path.basename(full_path) for full_path in glob.glob("./photos/*")}
    search_keys = [(save_key, search_key) for save_key, search_key in search_keys if save_key not in processed]

    #Parameters
    number_of_images = 3                # Desired number of images
    headless = True                     # True = No Chrome GUI
    min_resolution = (0, 0)             # Minimum desired image resolution
    max_resolution = (9999, 9999)       # Maximum desired image resolution
    max_missed = 100                    # Max number of failed images before exit
    number_of_workers = 8               # Number of "workers" used
    keep_filenames = False              # Keep original URL image filenames

    #Run each search_key in a separate thread
    #Automatically waits for all threads to finish
    #Removes duplicate strings from search_keys
    with concurrent.futures.ThreadPoolExecutor(max_workers=number_of_workers) as executor:
        executor.map(worker_thread, search_keys)
