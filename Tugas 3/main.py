import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('child_iq.csv')

education_mapping = {1: "no hs diploma", 2: "high school diploma", 3: "college dropout", 4: "college grad"}

df['educ_cat'] = df['educ_cat'].map(education_mapping)

education_totals = df.groupby('educ_cat').size()

print("jumlah dari lulusan jenjang tiap ibu:")
print(education_totals, "\n")

print("nilai tinggi iq: ", df['ppvt'].max(), "\n")

print("nilai rendah iq: ", df['ppvt'].min(), "\n")

print("rata rata iq: ", df['ppvt'].mean(), "\n")

print("rata rata umur ibu: ", df['momage'].mean(), "\n")

print("deskripsi statistik: \n")
print(df.describe())

mean_ppvt = df.groupby('educ_cat')['ppvt'].mean()

# Plotting the line graph
mean_ppvt.plot(kind='line', marker='o')

# Adding labels and title
plt.xlabel('Education Category')
plt.ylabel('Mean PPVT Score')
plt.title('Mean PPVT Score by Education Category')

# Rotating x-axis labels for better readability (optional)
plt.xticks(rotation=45)

# Displaying the plot
plt.grid(True)
plt.tight_layout()
plt.show()