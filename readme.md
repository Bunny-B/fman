
---

# **IDA Plugin Sample**

This project requires the IDA SDK for compilation and includes a post-build event to deploy the compiled plugin to your IDA Pro installation directory.

---

## **Getting Started**

### **Requirements**
1. **IDA Pro 9.0** installed on your system.
2. **IDA SDK**:
   - The IDA SDK is not included in this repository. You need to download it separately and place it in the `vendor/SDK/` directory.
   - The folder structure should look like this:
     ```
     mutatePlugin/
     ├── src/
     ├── vendor/
         └── SDK/
             ├── include/
             ├── lib/
             └── other_sdk_files...
     ```

---

### **Post-Build Event**
This project includes a post-build command in the Visual Studio project file that copies the compiled plugin to your IDA Pro `plugins` folder automatically after a successful build.

#### Default Post-Build Command:
```xml
<PostBuildEvent>
    <Command>xcopy /Y "$(TargetPath)" "$(ProgramFiles)\IDA Professional 9.0\plugins\"</Command>
</PostBuildEvent>
```

### **Modifying the Post-Build Command**
If your IDA Pro installation is in a different location, or you do not have write permissions to the `Program Files` directory, you must update the post-build event.

#### Steps to Modify:
1. Open the project in **Visual Studio**.
2. Go to **Project Properties** → **Build Events** → **Post-Build Event Command Line**.
3. Update the command to match your IDA installation path:
   ```
   xcopy /Y "$(TargetPath)" "C:\Path\To\Your\IDA\plugins\"
   ```
4. Alternatively, you can disable the post-build event and manually copy the compiled `.dll` file to the `plugins` directory.

---

### **Building the Plugin**

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/mutatePlugin.git
   cd mutatePlugin
   ```

2. Add the IDA SDK to `vendor/SDK/`.

3. Open the `mutatePlugin.sln` file in **Visual Studio 2022**.

4. Build the project.

5. (Optional) If the post-build event is configured, the plugin will be automatically copied to your IDA `plugins` directory. If not, manually copy the `.dll` to the directory.

